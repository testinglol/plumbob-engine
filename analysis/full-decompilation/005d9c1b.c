
void __thiscall FUN_005d9c1b(int param_1,int *param_2)

{
  int iVar1;
  char cVar2;
  DWORD DVar3;
  undefined4 uVar4;
  undefined4 *puVar5;
  undefined1 local_10 [11];
  char local_5;
  
  local_5 = '\0';
  if (param_2 != (int *)0x0) {
    cVar2 = (**(code **)(*param_2 + 0x8c))(1);
    if (cVar2 != '\0') {
      local_5 = (**(code **)(*param_2 + 0x8c))(0x400);
    }
  }
  if ((*(char *)(param_1 + 0x1a0) != '\0') && (*(char *)(param_1 + 0x1a1) != '\0')) {
    (**(code **)(**(int **)(param_1 + 0x2c) + 0x170))(param_1 + 0x1a4);
  }
  *(int **)(param_1 + 0x174) = param_2;
  if (local_5 == '\0') {
    DVar3 = timeGetTime();
    if (*(int *)(param_1 + 0x174) == 0) {
      *(undefined4 *)(param_1 + 0x178) = 1;
    }
    else if (*(int *)(*(int *)(param_1 + 0x174) + 0xa4) <=
             (int)(DVar3 - *(DWORD *)(param_1 + 0x17c))) {
      *(undefined4 *)(param_1 + 0x178) = 1;
      *(DWORD *)(param_1 + 0x17c) = DVar3;
    }
  }
  else {
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
        goto LAB_005d9d07;
      }
      *(undefined4 *)(param_1 + 0x178) = 3;
    }
    DVar3 = timeGetTime();
    *(DWORD *)(param_1 + 0x17c) = DVar3;
  }
LAB_005d9d07:
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
  if (local_5 != '\0') {
    uVar4 = (**(code **)(**(int **)(param_1 + 0x174) + 0xb8))();
    *(undefined4 *)(param_1 + 0x18c) = uVar4;
    *(undefined1 *)(param_1 + 0x1a1) = 0;
  }
  *(char *)(param_1 + 0x1a0) = local_5;
  if (*(int *)(param_1 + 0x18c) != 0) {
    puVar5 = (undefined4 *)
             (**(code **)(**(int **)(param_1 + 0x174) + 0xbc))(local_10,*(int *)(param_1 + 0x18c),0)
    ;
    *(undefined4 *)(param_1 + 0x184) = *puVar5;
    *(undefined4 *)(param_1 + 0x188) = puVar5[1];
    FUN_005ddfdc(1);
  }
  return;
}

