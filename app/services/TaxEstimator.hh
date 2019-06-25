<?hh // strict

namespace App\Services;

use App\Models\Billable;

class TaxEstimator
{
  protected Billable $billable;

  public function __construct(Billable $billable)
  {
    $this->billable = $billable;
  }


  public function calculate(): Billable
  {
    return $this->billable;
  }
}
