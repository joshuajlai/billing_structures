<?hh // strict

namespace App\Calculators\Billable;

use App\Models\{Billable, LineItem, AdjustmentType};
use App\Calculators\{Base, Calculator, TaxEstimator};

class Estimation implements Calculator
{
  use Base;

  protected Billable $billable;

  public function __construct(Billable $billable)
  {
    $this->billable = $billable;
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
}
