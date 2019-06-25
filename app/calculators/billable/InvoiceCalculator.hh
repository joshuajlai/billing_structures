<?hh // strict

namespace App\Calculators\Billable;

use App\Models\{Billable, Invoice, LineItem, AdjustmentType};
use App\Calculators\{Base, Calculator, TaxCalculator};

class InvoiceCalculator implements Calculator
{
  use Base;

  protected Invoice $billable;

  public function __construct(Invoice $billable)
  {
    $this->billable = $billable;
  }

  public function tax(): int
  {
    $taxCalculator = new TaxCalculator($this->billable);
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
}
