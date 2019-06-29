<?hh //strict

namespace App\Controllers\Subscription;

use App\Models\Subscription;
use App\Calculators\Billable\Estimation as EstimationCalculator;

type BillableTotals = shape(
  'total' => int,
  'subtotal' => int,
  'tax' => int
);

class Estimate
{
  public function call(Subscription $subscription): BillableTotals
  {
    $estimationCalculator = new EstimationCalculator($subscription);

    return shape(
      'total' => $estimationCalculator->total(),
      'subtotal' => $estimationCalculator->subtotal(),
      'tax' => $estimationCalculator->tax()
    );
  }
}
