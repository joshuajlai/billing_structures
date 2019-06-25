<?hh //strict

namespace App\Controllers\Plan;

use App\Models\{Invoice, Plan};
use App\Calculators\Billable\Estimation as EstimationCalculator;
use App\Controllers\Invoice\{ConvertFromPlan, Finalize};

class Bill
{
  public function call(Plan $plan): Invoice
  {
    $converter = new ConvertFromPlan();
    $invoice = $converter->call($plan, true);

    $finalizer = new Finalize();
    $finalizer->call($invoice);

    return $invoice;
  }
}
