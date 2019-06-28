<?hh //strict

namespace App\Controllers\Subscription;

use App\Models\{Invoice, Subscription};
use App\Calculators\Billable\Estimation as EstimationCalculator;
use App\Controllers\Invoice\{ConvertFromSubscription, Finalize};

class Bill
{
  public function call(Subscription $subscription): Invoice
  {
    $converter = new ConvertFromSubscription();
    $invoice = $converter->call($subscription, true);

    $finalizer = new Finalize();
    $finalizer->call($invoice);

    return $invoice;
  }
}
