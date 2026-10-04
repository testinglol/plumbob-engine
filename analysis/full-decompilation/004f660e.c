
void __thiscall FUN_004f660e(int param_1,int param_2)

{
  undefined4 uVar1;
  
  if ((*(int *)(param_1 + 0xa0) == 0) || (*(char *)(param_1 + 0xf5) != '\0')) {
    *(undefined1 *)(param_1 + 0xfd) = 0;
  }
  else {
    if (param_2 < 0) {
      param_2 = 1000 - param_2;
    }
    (**(code **)(*DAT_006fe8bc + 0x18))();
    uVar1 = *(undefined4 *)(param_1 + 0xa0);
    FUN_005d9dba();
    FUN_005dac30(0x10,uVar1,param_2);
  }
  return;
}

