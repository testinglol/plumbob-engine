
void __fastcall FUN_005d9e18(int param_1)

{
  int iVar1;
  char cVar2;
  DWORD DVar3;
  undefined4 uVar4;
  undefined4 *puVar5;
  
  if (*(int *)(param_1 + 0x174) == 0) {
    return;
  }
  iVar1 = *(int *)(param_1 + 0x178);
  if (iVar1 == 0) {
    *(undefined4 *)(param_1 + 0x178) = 1;
  }
  else {
    if (iVar1 != 2) {
      if (iVar1 == 3) {
        *(undefined4 *)(param_1 + 0x178) = 2;
        DVar3 = timeGetTime();
        *(DWORD *)(param_1 + 0x180) = DVar3;
      }
      goto LAB_005d9e76;
    }
    *(undefined4 *)(param_1 + 0x178) = 3;
  }
  DVar3 = timeGetTime();
  *(DWORD *)(param_1 + 0x17c) = DVar3;
LAB_005d9e76:
  cVar2 = FUN_005da398(*(undefined4 *)(param_1 + 0x18c));
  if (cVar2 == '\0') {
    *(undefined4 *)(param_1 + 0x18c) = 0;
  }
  else {
    (**(code **)(**(int **)(param_1 + 0x18c) + 0xc0))(*(int **)(param_1 + 0x18c) + 0x1f,0);
    (**(code **)(**(int **)(param_1 + 0x18c) + 8))();
    *(undefined4 *)(param_1 + 0x18c) = 0;
    *(undefined1 *)(param_1 + 0x1a1) = 0;
  }
  cVar2 = (**(code **)(**(int **)(param_1 + 0x174) + 0x8c))(0x400);
  if (cVar2 != '\0') {
    uVar4 = (**(code **)(**(int **)(param_1 + 0x174) + 0xb8))();
    *(undefined4 *)(param_1 + 0x18c) = uVar4;
    *(undefined1 *)(param_1 + 0x1a1) = 0;
  }
  if (*(int *)(param_1 + 0x18c) != 0) {
    FUN_005ddfdc(1);
    puVar5 = (undefined4 *)
             (**(code **)(**(int **)(param_1 + 0x174) + 0xbc))
                       (&stack0xfffffff4,*(undefined4 *)(param_1 + 0x18c),0);
    *(undefined4 *)(param_1 + 0x184) = *puVar5;
    *(undefined4 *)(param_1 + 0x188) = puVar5[1];
  }
  return;
}

