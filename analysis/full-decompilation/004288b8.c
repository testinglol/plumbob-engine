
void __thiscall FUN_004288b8(int param_1,uint param_2,undefined4 *param_3,undefined4 *param_4)

{
  int iVar1;
  undefined4 uVar2;
  
  if (((int)param_2 < 1) ||
     ((uint)(*(int *)(param_1 + 0x114) - *(int *)(param_1 + 0x110) >> 3) <= param_2)) {
    *param_4 = 0;
    *param_3 = 0;
  }
  else {
    iVar1 = *(int *)(param_1 + 0x110);
    uVar2 = *(undefined4 *)(iVar1 + param_2 * 8 + 4);
    *param_3 = *(undefined4 *)(iVar1 + param_2 * 8);
    *param_4 = uVar2;
  }
  return;
}

