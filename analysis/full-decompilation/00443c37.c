
void __thiscall FUN_00443c37(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  int *local_8;
  
  iVar1 = *(int *)(param_1 + 0x3c);
  iVar2 = *(int *)(param_1 + 0x38);
  local_8 = *(int **)(param_1 + 0x38);
  do {
    if (local_8 == *(int **)(param_1 + 0x3c)) {
LAB_00443cad:
      if ((iVar1 - iVar2 >> 2 != 0) !=
          (*(int *)(param_1 + 0x3c) - *(int *)(param_1 + 0x38) >> 2 != 0)) {
        FUN_0040766a(0x108,0);
      }
      return;
    }
    if (*local_8 == param_2) {
      FUN_004486a3(local_8);
      goto LAB_00443cad;
    }
    local_8 = local_8 + 1;
  } while( true );
}

