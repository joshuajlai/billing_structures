<?hh //strict

namespace App\Controllers\Invoice;

use App\Models\Invoice;
use App\Calculators\Billable\Estimation as EstimationCalculator;

type BillableTotals = shape(
  'total' => int,
  'subtotal' => int,
  'tax' => int
);

class Estimation
{
  public function call(Invoice $invoice): BillableTotals
  {
    $estimationCalculator = new EstimationCalculator($invoice);

    return shape(
      'total' => $estimationCalculator->total(),
      'subtotal' => $estimationCalculator->subtotal(),
      'tax' => $estimationCalculator->tax()
    );
  }
}
