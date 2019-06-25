<?hh // strict

namespace App\Calculators;

use App\Models\Billable;
use App\Services\TaxService;

class TaxEstimator
{
  protected Billable $billable;

  public function __construct(Billable $billable)
  {
    $this->billable = $billable;
  }

  public function totalTax(): int
  {
    $taxService = new TaxService();
    $billable = $taxService->estimateTax($this->billable);
    $total = 0;
    $lineItemCalculator = new ItemCalculator();
    foreach ($billable->getLineItems() as $lineItem) {
      $total += $lineItemCalculator->tax($lineItem);
    }

    return $total;
  }
}
