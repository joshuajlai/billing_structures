<?hh // strict

namespace App\Models;

enum SubscriptionStatus: string {
  Pending = 'pending';
  Active = 'active';
  Inactive = 'inactive';
}

class Subscription extends Billable
{
  private SubscriptionStatus $status;

  public function __construct()
  {
    $this->status = SubscriptionStatus::Pending;
  }

  public function activate(): void
  {
    $this->status = SubscriptionStatus::Active;
  }

  public function deactivate(): void
  {
    $this->status = SubscriptionStatus::Inactive;
  }
}
