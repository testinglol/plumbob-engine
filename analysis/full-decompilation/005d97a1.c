
void __fastcall FUN_005d97a1(int param_1)

{
  int *piVar1;
  char cVar2;
  undefined4 uVar3;
  int iVar4;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  char local_5;
  
  uVar3 = FUN_005d51f5(s_FW__Plot_006d731c,0);
  FUN_004b406a(uVar3);
  local_5 = FUN_005d9f30();
  iVar4 = (**(code **)(**(int **)(param_1 + 0x48) + 0x1c))();
  iVar4 = (**(code **)(*(int *)((-(uint)(iVar4 != 0) & iVar4 - 0x48U) + 0x48) + 0x24))();
  if (((local_5 != '\0') && (iVar4 != 0)) && (*(char *)(iVar4 + 0x91) != '\0')) {
    iVar4 = *(int *)(param_1 + 0x18c);
    local_18 = *(undefined4 *)(iVar4 + 0x7c);
    local_14 = *(undefined4 *)(iVar4 + 0x80);
    local_10 = *(undefined4 *)(iVar4 + 0x84);
    local_c = *(undefined4 *)(iVar4 + 0x88);
    FUN_005ecd7f(&local_18,iVar4);
  }
  piVar1 = *(int **)(*(int *)(param_1 + 0x2c) + 0xec);
  if (piVar1 != (int *)0x0) {
    cVar2 = (**(code **)(*piVar1 + 0x8c))(1);
    if (cVar2 != '\0') {
      (**(code **)(*piVar1 + 0x44))();
    }
  }
  if (*(char *)(param_1 + 0x1f8) == '\0') {
    FUN_005db0e6();
  }
  (**(code **)(**(int **)(param_1 + 0x2c) + 0x178))(1);
  if (local_5 == '\0') {
    *(undefined1 *)(param_1 + 0x1b4) = 0;
  }
  else {
    FUN_005da2bc();
  }
  return;
}

