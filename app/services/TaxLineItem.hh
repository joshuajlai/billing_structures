<?hh // strict

namespace App\Services;

class TaxLineItem
{
  protected string $name;
  protected int $value;

  public function __construct(string $name, int $value)
  {
    $this->name = $name;
    $this->value = $value;
  }

  public function getName(): string
  {
    return $this->name;
  }

  public function getValue(): int
  {
    return $this->value;
  }
}
