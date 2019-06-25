<?hh // strict

namespace App\Services;

use App\Models\{Billable, Invoice};

class TaxService
{
  public function estimateTax(Billable $billable): Billable
  {
    $estimator = new TaxEstimator($billable);
    return $estimator->calculate();
  }

  public function calculateTax(Invoice $billable): Invoice
  {
    $remitter = new TaxRemitter($billable);
    return $remitter->calculate();
  }
}
