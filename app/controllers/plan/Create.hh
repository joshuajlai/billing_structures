<?hh // strict

namespace App\Controllers\Plan;

use App\Models\Plan;

class Create
{
  public function call(): Plan
  {
    return new Plan();
  }
}
