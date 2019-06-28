<?hh // strict

namespace App\Controllers\Subscription;

use App\Models\Subscription;

class Deactivate
{
  public function call(Subscription $subscription): Subscription
  {
    $subscription->deactivate();

    return $subscription;
  }
}
