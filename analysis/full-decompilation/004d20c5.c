
undefined4 __thiscall
FUN_004d20c5(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  char cVar1;
  int iVar2;
  undefined4 uVar3;
  undefined1 local_24 [16];
  int local_14;
  int local_10;
  int local_c;
  int local_8;
  
  if (*(int **)(param_1 + 0x174) != (int *)0x0) {
    (**(code **)(**(int **)(param_1 + 0x174) + 0xc))(param_2,param_3,param_4);
  }
  iVar2 = FUN_00401f6f();
  if (iVar2 == 4) {
    cVar1 = FUN_004d3d05();
    if (cVar1 != '\0') {
      uVar3 = FUN_004b16b0(local_24);
      FUN_005de822(uVar3);
      local_14 = local_14 + 1;
      local_c = local_c + -1;
      local_10 = local_10 + 1;
      local_8 = local_8 + -1;
      FUN_004b17e5(&local_14,1,0);
    }
  }
  return 1;
}

