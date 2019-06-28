<?hh // strict

namespace App\Controllers\Invoice;

use App\Models\{Subscription, Invoice, UnsavedInvoice, LineItem, LineItemAdjustment};

class ConvertFromSubscription
{
  public function call(Subscription $subscription, bool $save): Invoice
  {
    if ($save == true) {
      $invoice = new Invoice();
    } else {
      $invoice = new UnsavedInvoice();
    }

    foreach ($subscription->getLineItems() as $lineItem) {
      $newLineItem = new LineItem($lineItem->getName());
      foreach ($lineItem->getLineItemAdjustments() as $adjustment) {
        $newAdjustment = new LineItemAdjustment(
          $adjustment->getValue(), $adjustment->getType()
        );
        $newLineItem->addLineItemAdjustment($newAdjustment);
      }
      $invoice->addLineItem($newLineItem);
    }

    return $invoice;
  }
}
