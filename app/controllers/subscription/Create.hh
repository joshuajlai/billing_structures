<?hh // strict

namespace App\Controllers\Subscription;

use App\Models\Subscription;

class Create
{
  public function call(): Subscription
  {
    return new Subscription();
  }
}
