
void __fastcall FUN_00415e60(int param_1)

{
  int iVar1;
  
  if (*(undefined4 **)(param_1 + 0x20) != (undefined4 *)0x0) {
    (**(code **)**(undefined4 **)(param_1 + 0x20))(1);
  }
  *(undefined4 *)(param_1 + 0x20) = 0;
  if (*(undefined4 **)(param_1 + 0x18) != (undefined4 *)0x0) {
    (**(code **)**(undefined4 **)(param_1 + 0x18))(1);
  }
  *(undefined4 *)(param_1 + 0x18) = 0;
  *(undefined4 *)(param_1 + 0x1c) = 0;
  if (*(int *)(param_1 + 0x14) != 0) {
    FUN_0044069b();
  }
  if (*(undefined4 **)(param_1 + 0x14) != (undefined4 *)0x0) {
    (**(code **)**(undefined4 **)(param_1 + 0x14))(1);
  }
  iVar1 = *(int *)(param_1 + 0x24);
  *(undefined4 *)(param_1 + 0x14) = 0;
  if (iVar1 != 0) {
    FUN_00466ac4();
    FUN_006321f0(iVar1);
  }
  iVar1 = *(int *)(param_1 + 0x68);
  *(undefined4 *)(param_1 + 0x24) = 0;
  *(undefined4 *)(param_1 + 0x10) = 0;
  if (iVar1 != 0) {
    FUN_0046143b();
    FUN_006321f0(iVar1);
  }
  iVar1 = *(int *)(param_1 + 0x6c);
  *(undefined4 *)(param_1 + 0x68) = 0;
  if (iVar1 != 0) {
    FUN_0046143b();
    FUN_006321f0(iVar1);
  }
  *(undefined4 *)(param_1 + 0x6c) = 0;
  return;
}

