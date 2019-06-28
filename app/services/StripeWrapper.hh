<?hh

namespace App\Services;

use \App\Models\{Subscription, LineItem};
use \Stripe\Subscription as StripeSubscription;
use \Stripe\Plan as StripePlan;

/**
 *  API wrapper class to convert models into Stripe entities.
 */
class StripeWrapper
{
  public function createSubscription(Subscription $subscription): StripeSubscription
  {
    $payload = dict[
      'items' => vec[]
    ];
    foreach ($subscription->getLineItems() as $lineItem) {
      $plan = $this->findPlan($lineItem);
      $payload['items'][] = dict[
        'plan' => $plan->id
      ];
    }

    return new StripeSubscription();
  }

  public function findPlan(LineItem $lineItem): StripePlan
  {
    return new StripePlan();
  }
}
