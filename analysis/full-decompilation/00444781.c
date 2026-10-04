
void __thiscall FUN_00444781(int param_1,undefined4 param_2,undefined2 param_3)

{
  undefined4 uVar1;
  short sVar2;
  int local_10;
  undefined2 local_c;
  undefined2 local_a;
  undefined2 local_8;
  undefined2 local_6;
  
  local_c = param_3;
  local_a = 0;
  local_8 = 0;
  local_6 = 0;
  for (local_10 = *(int *)(param_1 + 0x30); local_10 != 0; local_10 = *(int *)(local_10 + 0xe0)) {
    uVar1 = *(undefined4 *)(*(int *)(local_10 + 0x11c) + 0xc);
    sVar2 = FUN_00402246(param_2);
    if (sVar2 != 0) {
      FUN_00474c68(uVar1,0,sVar2,&local_c);
    }
  }
  return;
}

