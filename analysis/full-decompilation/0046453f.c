
void __fastcall FUN_0046453f(int param_1)

{
  if ((*(int *)(param_1 + 0xc) == 1) && (*(int *)(param_1 + 0x14) != 0)) {
    FUN_0046fd72();
  }
  if (*(undefined4 **)(param_1 + 0x14) != (undefined4 *)0x0) {
    (**(code **)**(undefined4 **)(param_1 + 0x14))(1);
  }
  *(undefined4 *)(param_1 + 0x14) = 0;
  return;
}

