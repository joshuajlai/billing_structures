<?hh // strict

namespace App\Controllers\Invoice;

use App\Models\{LineItem, LineItemAdjustment, Invoice, AdjustmentType};

class AddProduct
{
  public function call(Invoice $invoice, string $name, int $value): Invoice
  {
    $lineItem = new LineItem($name);
    $lineItemAdjustment = new LineItemAdjustment($value, AdjustmentType::Product);
    $lineItem->addLineItemAdjustment($lineItemAdjustment);
    $invoice->addLineItem($lineItem);

    return $invoice;
  }
}
