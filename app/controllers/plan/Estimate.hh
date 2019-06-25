<?hh //strict

namespace App\Controllers\Plan;

use App\Models\Plan;
use App\Calculators\Billable\Estimation as EstimationCalculator;

type BillableTotals = shape(
  'total' => int,
  'subtotal' => int,
  'tax' => int
);

class Estimation
{
  public function call(Plan $plan): BillableTotals
  {
    $estimationCalculator = new EstimationCalculator($plan);

    return shape(
      'total' => $estimationCalculator->total(),
      'subtotal' => $estimationCalculator->subtotal(),
      'tax' => $estimationCalculator->tax()
    );
  }
}
