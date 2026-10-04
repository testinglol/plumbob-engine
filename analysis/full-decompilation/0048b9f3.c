
void __thiscall FUN_0048b9f3(int param_1,int param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = *(int *)(param_1 + 0x2c);
  if (iVar1 != 0) {
    if (param_2 == 0) {
      *(undefined2 *)(iVar1 + 0x4a) = 0;
    }
    else if (param_2 == 1) {
      *(undefined2 *)(iVar1 + 0x4a) = 1;
    }
    else if (param_2 == 2) {
      *(undefined2 *)(iVar1 + 0x4a) = 3;
    }
  }
  if (param_2 != 0) {
    if (param_2 == 1) {
      uVar2 = 6;
      goto LAB_0048ba33;
    }
    if (param_2 != 2) {
      return;
    }
  }
  uVar2 = 0;
LAB_0048ba33:
  FUN_004d25a5(uVar2);
  return;
}

