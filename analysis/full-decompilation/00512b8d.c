
undefined4 __thiscall FUN_00512b8d(int param_1,int param_2,int param_3)

{
  int iVar1;
  bool bVar2;
  
  iVar1 = *(int *)(param_1 + 0x120);
  if (iVar1 != 0) {
    bVar2 = false;
    if (param_2 < 6) {
      bVar2 = true;
    }
    else if (param_2 < 0xc3) {
      param_2 = 0xc3;
    }
    if (param_3 < 6) {
      bVar2 = true;
    }
    else if (param_3 < 0xc3) {
      param_3 = 0xc3;
    }
    if (iVar1 == 1) {
      if (bVar2) {
        FUN_00512c83(param_2 + -5,param_3 + -5);
        param_3 = (*(int *)(param_1 + 0x88) - *(int *)(param_1 + 0x80)) - param_2;
        param_2 = (*(int *)(param_1 + 0x84) - *(int *)(param_1 + 0x7c)) - param_2;
      }
      FUN_004cb1a2(param_2 + 5,param_3 + 5);
    }
    else if (iVar1 == 2) {
      if (bVar2) {
        FUN_00512c83(param_2 + -5,0);
        param_2 = (*(int *)(param_1 + 0x84) - *(int *)(param_1 + 0x7c)) - param_2;
      }
      FUN_004ec186(param_2 + 5);
    }
    else {
      if (bVar2) {
        FUN_00512c83(0,param_3 + -5);
        param_3 = (*(int *)(param_1 + 0x88) - *(int *)(param_1 + 0x80)) - param_3;
      }
      FUN_004ec1a7(param_3 + 5);
    }
  }
  return 1;
}

