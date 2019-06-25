<?hh // strict

namespace App\Controllers\Plan;

use App\Models\Plan;

class Deactivate
{
  public function call(Plan $plan): Plan
  {
    $plan->deactivate();

    return $plan;
  }
}
