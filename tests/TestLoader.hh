<?hh // strict

use App\Models\{
  Invoice, LineItem, LineItemAdjustment, AdjustmentType, Plan
};

trait TestLoader
{
  /**
   * Generate a test invoice
   */
  public function generateInvoice(): Invoice
  {
    $invoice = new Invoice();

    for($i = 0; $i < 3; $i++) {
      $lineItem = new LineItem("Item {$i}");
      $lineItemAdjustment = new LineItemAdjustment(
        $i * 100, AdjustmentType::Product
      );
      $lineItem->addLineItemAdjustment($lineItemAdjustment);
      $invoice->addLineItem($lineItem);
    }

    return $invoice;
  }

  /**
   * Generate a test invoice
   */
  public function generatePlan(): Plan
  {
    $invoice = new Plan();

    for($i = 0; $i < 3; $i++) {
      $lineItem = new LineItem("Item {$i}");
      $lineItemAdjustment = new LineItemAdjustment(
        $i * 100, AdjustmentType::Product
      );
      $lineItem->addLineItemAdjustment($lineItemAdjustment);
      $invoice->addLineItem($lineItem);
    }

    return $invoice;
  }
}
