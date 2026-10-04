
void __thiscall FUN_0043cb5d(int param_1,int param_2,undefined4 param_3,int param_4)

{
  int *piVar1;
  int iVar2;
  int local_14;
  undefined4 local_10;
  int local_c;
  undefined4 local_8;
  
  piVar1 = *(int **)(param_1 + 0x20);
  do {
    if (piVar1 == *(int **)(param_1 + 0x24)) {
LAB_0043cb84:
      FUN_0043e36d(&param_2);
LAB_0043cb8d:
      FUN_00575b11(&local_c,&param_3);
      if (local_c != 0) {
        local_14 = local_c;
        local_10 = local_8;
        FUN_0057644e(&local_14);
      }
      local_10 = 0;
      local_14 = param_4;
      iVar2 = FUN_0043ed84(&local_14);
      *(int *)(iVar2 + 4) = param_2;
      return;
    }
    if (*piVar1 == param_2) {
      if (piVar1 != *(int **)(param_1 + 0x24)) goto LAB_0043cb8d;
      goto LAB_0043cb84;
    }
    piVar1 = piVar1 + 1;
  } while( true );
}

