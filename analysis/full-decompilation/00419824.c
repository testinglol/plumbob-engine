
void __fastcall FUN_00419824(int *param_1)

{
  char cVar1;
  int iVar2;
  int *piVar3;
  undefined4 uVar4;
  int local_c;
  int local_8;
  
  cVar1 = (**(code **)(*param_1 + 0x28))();
  if (cVar1 == '\0') {
    uVar4 = 0xffffffcf;
  }
  else {
    uVar4 = 0;
  }
  FUN_004659fc(uVar4);
  iVar2 = FUN_00401f6f();
  if (iVar2 != 0) {
    return;
  }
  local_8 = 0;
  local_c = (((int *)param_1[6])[1] - *(int *)param_1[6]) / 0x14;
  if (0 < local_c) {
    do {
      uVar4 = FUN_00418f0b(local_c);
      for (iVar2 = FUN_00418f37(uVar4); 0 < iVar2; iVar2 = iVar2 + -1) {
        piVar3 = (int *)FUN_00418e78(uVar4,iVar2,0);
        if ((*piVar3 == -1) && ((**(code **)(*param_1 + 0x7c))(piVar3[3]), local_8 == 0)) {
          local_8 = FUN_00401f6f();
        }
      }
      local_c = local_c + -1;
    } while (0 < local_c);
    if (local_8 != 0) goto LAB_004198d3;
  }
  local_8 = FUN_004131cb();
LAB_004198d3:
  FUN_004659fc(local_8);
  return;
}

