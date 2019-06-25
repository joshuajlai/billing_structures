<?hh // strict

namespace App\Controllers\Invoice;

use App\Models\{Plan, Invoice, UnsavedInvoice, LineItem, LineItemAdjustment};

class ConvertFromPlan
{
  public function call(Plan $plan, bool $save): Invoice
  {
    if ($save == true) {
      $invoice = new Invoice();
    } else {
      $invoice = new UnsavedInvoice();
    }

    foreach ($plan->getLineItems() as $lineItem) {
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
