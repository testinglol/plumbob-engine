
void __thiscall FUN_005450fd(int param_1,undefined4 param_2)

{
  undefined4 uVar1;
  uint uVar2;
  undefined **local_110;
  undefined4 local_10c;
  undefined1 local_104 [256];
  
  uVar2 = 0;
  *(undefined4 *)(param_1 + 0xd4) = param_2;
  if (*(int *)(param_1 + 0xdc) - *(int *)(param_1 + 0xd8) >> 2 != 0) {
    do {
      if (*(int *)(*(int *)(param_1 + 0xd8) + uVar2 * 4) != 0) {
        FUN_00521647(param_2);
      }
      uVar2 = uVar2 + 1;
    } while (uVar2 < (uint)(*(int *)(param_1 + 0xdc) - *(int *)(param_1 + 0xd8) >> 2));
  }
  FUN_004e9bbd(param_2);
  uVar1 = FUN_004096c2();
  FUN_005d4bbf(uVar1);
  FUN_0046f824(local_104,0,0x100);
  local_110 = &PTR_FUN_00666524;
  FUN_004e9d38(*(undefined4 *)(param_1 + 0xd4),&local_110);
  wsprintfA((LPSTR)(param_1 + 0x148),DAT_006f4f80,local_10c);
  FUN_00545386();
  return;
}

