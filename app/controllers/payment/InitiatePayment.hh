<?hh // strict

namespace App\Controllers\Payment;

use App\Models\{Invoice, Payment, PaymentSource, Transaction};

type PaymentDistribution = shape(
  'paymentSource' => PaymentSource,
  'amount' => int
);

class InitiatePayment
{
  public function call(Invoice $invoice, vec<PaymentDistribution> $distributions): Payment
  {
    $payment = new Payment($invoice->getId());
    foreach ($distributions as $distribution) {
      $transaction = new Transaction(
        $distribution['paymentSource'],
        $distribution['amount']
      );
      $payment->addTransaction($transaction);
    }

    return $payment;
  }
}
