<?hh // strict

namespace App\Calculators\Billable;

use App\Models\{Billable, Subscription, LineItem};
use App\Calculators\{Base, Calculator, TaxEstimator};
use App\Controllers\Invoice\ConvertFromSubscription;

class Estimation implements Calculator
{
  use Base;

  protected Billable $billable;

  public function __construct(Billable $billable)
  {
    $this->billable = $this->processBillable($billable);
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

  private function processBillable(Billable $billable): Billable
  {
    if ($billable is Subscription) {
      $convertController = new ConvertFromSubscription();
      return $convertController->call($billable, false);
    }

    return $billable;
  }
}
