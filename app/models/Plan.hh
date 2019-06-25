<?hh // strict

namespace App\Models;

enum PlanStatus: string {
  Pending = 'pending';
  Active = 'active';
  Inactive = 'inactive';
}

class Plan extends Billable
{
  private PlanStatus $status;

  public function __construct()
  {
    $this->status = PlanStatus::Pending;
  }

  public function activate(): void
  {
    $this->status = PlanStatus::Active;
  }

  public function deactivate(): void
  {
    $this->status = PlanStatus::Inactive;
  }
}
