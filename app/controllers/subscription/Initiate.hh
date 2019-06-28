<?hh // strict

namespace App\Controllers\Subscription;

use App\Models\Subscription;

class Initiate
{
  public function call(Subscription $subscription): Subscription
  {
    $subscription->activate();

    return $subscription;
  }
}
