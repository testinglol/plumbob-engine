
void __thiscall FUN_0046d7b3(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  
  if (param_2 < 0) {
    param_2 = 0;
  }
  if (1000 < param_2) {
    param_2 = 1000;
  }
  *(undefined2 *)(param_1 + 0x30) = (undefined2)param_2;
  iVar1 = __ftol();
  *(undefined4 *)(param_1 + 0xbc) = 0;
  *(int *)(param_1 + 0xc0) = iVar1;
  *(undefined4 *)(param_1 + 0xb8) = 0;
  FUN_004733da(iVar1);
  iVar1 = *(int *)(param_1 + 0xc0);
  iVar2 = (iVar1 * 0x3c) / 0x2a;
  if (0x3c < iVar2) {
    iVar2 = 0x3c;
  }
  if (iVar2 < 1) {
    iVar2 = 1;
  }
  if (0x3c < iVar2) {
    iVar2 = 0x3c;
  }
  *(int *)(param_1 + 0xd8) = iVar2;
  iVar1 = FUN_0046d888(iVar1);
  if (iVar1 < 1) {
    iVar1 = 1;
  }
  if (0x5a < iVar1) {
    iVar1 = 0x5a;
  }
  *(int *)(param_1 + 0xdc) = iVar1;
  FUN_0040766a(0xc2,0);
  if (-1 < *(short *)(param_1 + 0x34)) {
    *(undefined2 *)(param_1 + 0x34) = (undefined2)param_2;
  }
  return;
}

