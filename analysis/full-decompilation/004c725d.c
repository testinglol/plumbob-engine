
void __fastcall FUN_004c725d(undefined4 *param_1)

{
  int *piVar1;
  short sVar2;
  int iVar3;
  undefined4 uVar4;
  int local_c;
  short local_6;
  
  iVar3 = FUN_004b8e50();
  if (iVar3 == 0) {
    FUN_004c915f();
  }
  piVar1 = (int *)*param_1;
  sVar2 = (**(code **)(*piVar1 + 0x34))(0x53505223);
  local_c = 1;
  if (0 < sVar2) {
    do {
      uVar4 = (**(code **)(*piVar1 + 0x40))(0x53505223,local_c,FUN_004c90d0);
      (**(code **)(*piVar1 + 0x50))(uVar4,&local_6);
      FUN_004c8f7a((int)local_6);
      local_c = local_c + 1;
    } while (local_c <= sVar2);
  }
  sVar2 = (**(code **)(*piVar1 + 0x34))(0x53505232);
  local_c = 1;
  if (0 < sVar2) {
    do {
      uVar4 = (**(code **)(*piVar1 + 0x40))(0x53505232,local_c,0);
      (**(code **)(*piVar1 + 0x50))(uVar4,&local_6);
      FUN_004c8f7a((int)local_6);
      local_c = local_c + 1;
    } while (local_c <= sVar2);
  }
  return;
}

