<?hh //strict

/**
 * Simple usage flow for controller calls
 */

class SubscriptionScenario
{
  public function run(): void
  {
    $createController = new \App\Controllers\Subscription\Create();
    $subscription = $createController->call();

    $productController = new \App\Controllers\Subscription\AddProduct();
    $subscription = $productController->call($subscription, 'sku1');
    $subscription = $productController->call($subscription, 'sku2');

    $initiateController = new \App\Controllers\Subscription\Initiate();
    $subscription = $initiateController->call($subscription);

    $estimateController = new \App\Controllers\Subscription\Estimate();
    $expectedTotals = $estimateController->call($subscription);

    $billController = new \App\Controllers\Subscription\Bill();
    $invoice = $billController->call($subscription);

    $initiatePaymentController = new \App\Controllers\Payment\InitiatePayment();

    $distribution = vec[
      shape(
        'paymentSource' => new \App\Models\PaymentSource(),
        'amount' => 10000
      )
    ];
    $payment = $initiatePaymentController->call($invoice, $distribution);

    $executePaymentController = new \App\Controllers\Payment\ExecutePayment();
    $payment = $executePaymentController->call($payment);
  }
}
