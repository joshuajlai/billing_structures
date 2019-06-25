<?hh // strict

namespace App\Controllers\Invoice;

use App\Models\{LineItem, LineItemAdjustment, Invoice, AdjustmentType};

class RemoveProduct
{
  public function call(Invoice $invoice, LineItem $lineItem): Invoice
  {
    $invoice->removeLineItem($lineItem);

    return $invoice;
  }
}
