
void __fastcall FUN_005de1ac(int param_1)

{
  int iVar1;
  int iVar2;
  undefined2 uVar3;
  undefined2 uVar4;
  int iVar5;
  
  if (*(int *)(param_1 + 0x5c) != 0) {
    iVar5 = *(int *)(param_1 + 0xa0) * 0x10;
    uVar3 = FUN_005dfe3b(0,0,0);
    uVar4 = FUN_005dfe3b(100,0xff,100);
    iVar1 = *(int *)(param_1 + 0x20);
    iVar2 = *(int *)(param_1 + 0x1c);
    (**(code **)(**(int **)(param_1 + 0x5c) + 0x20))(4);
    (**(code **)(**(int **)(param_1 + 0x5c) + 0x7c))
              (*(int *)(&DAT_006d7400 + iVar5) + iVar2,*(int *)(&DAT_006d7404 + iVar5) + iVar1,
               *(int *)(&DAT_006d7408 + iVar5) + iVar2,*(int *)(&DAT_006d740c + iVar5) + iVar1,uVar3
               ,1);
    *(int *)(param_1 + 0xa0) = *(int *)(param_1 + 0xa0) + 1;
    if (3 < *(int *)(param_1 + 0xa0)) {
      *(undefined4 *)(param_1 + 0xa0) = 0;
    }
    iVar5 = *(int *)(param_1 + 0xa0) * 0x10;
    (**(code **)(**(int **)(param_1 + 0x5c) + 0x7c))
              (*(int *)(&DAT_006d7400 + iVar5) + iVar2,*(int *)(&DAT_006d7404 + iVar5) + iVar1,
               *(int *)(&DAT_006d7408 + iVar5) + iVar2,*(int *)(&DAT_006d740c + iVar5) + iVar1,uVar4
               ,1);
    (**(code **)(**(int **)(param_1 + 0x5c) + 0x24))(4);
  }
  return;
}

