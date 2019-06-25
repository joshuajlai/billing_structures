<?hh // strict

namespace App\Calculators\Billable;

use App\Models\{
  Billable, Invoice, UnsavedInvoice, LineItem, AdjustmentType, LineItemAdjustment
};
use App\Calculators\{Base, Calculator, TaxEstimator};

class Estimation implements Calculator
{
  use Base;

  protected Billable $billable;

  public function __construct(Billable $billable)
  {
    $this->billable = $billable;
    $this->processBillable();
  }

  public function tax(): int
  {
    $taxCalculator = new TaxEstimator($this->getBillable());
    return $taxCalculator->totalTax();
  }

  protected function filteredItems(): vec<LineItem>
  {
    return $this->getBillable()->getLineItems();
  }

  public function getBillable(): Billable
  {
    return $this->billable;
  }

  private function processBillable(): void
  {
    if ($this->billable is Invoice) {
      return;
    }

    // turn billable into an invoice
    $unsavedInvoice = new UnsavedInvoice();
    foreach ($this->billable->getLineItems() as $lineItem) {
      $newLineItem = new LineItem($lineItem->getName());
      foreach ($lineItem->getLineItemAdjustments() as $adjustment) {
        $newAdjustment = new LineItemAdjustment(
          $adjustment->getValue(), $adjustment->getType()
        );
        $newLineItem->addLineItemAdjustment($newAdjustment);
      }
      $unsavedInvoice->addLineItem($newLineItem);
    }

    $this->billable = $unsavedInvoice;
  }
}
