<?hh // strict

namespace App\Controllers\Plan;

use App\Models\Plan;

class Initiate
{
  public function call(Plan $plan): Plan
  {
    $plan->activate();

    return $plan;
  }
}
