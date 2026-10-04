
undefined4 __fastcall FUN_0050d5d6(int param_1)

{
  int iVar1;
  char cVar2;
  undefined4 uVar3;
  undefined1 *puVar4;
  int iVar5;
  undefined4 uVar6;
  undefined1 local_34 [16];
  undefined1 local_24 [16];
  undefined4 local_14;
  undefined4 local_10;
  int local_c;
  int local_8;
  
  if (*(int **)(param_1 + 0x5c) != (int *)0x0) {
    cVar2 = (**(code **)(**(int **)(param_1 + 0x5c) + 0x20))(0x10);
    if (cVar2 != '\0') {
      iVar5 = *(int *)(param_1 + 0xe0);
      local_14 = *(undefined4 *)(iVar5 + 0x14);
      local_10 = *(undefined4 *)(iVar5 + 0x18);
      local_c = *(int *)(iVar5 + 0x1c) / 3;
      local_8 = *(int *)(iVar5 + 0x20) / 3;
      (**(code **)(**(int **)(param_1 + 0x5c) + 0xc0))(iVar5,&local_14,param_1 + 0x1c,1);
      iVar5 = *(int *)(param_1 + 0xdc);
      uVar6 = 0;
      local_14 = *(undefined4 *)(iVar5 + 0x14);
      local_10 = *(undefined4 *)(iVar5 + 0x18);
      local_c = *(undefined4 *)(iVar5 + 0x1c);
      local_8 = *(undefined4 *)(iVar5 + 0x20);
      iVar1 = **(int **)(param_1 + 0x5c);
      iVar5 = param_1 + 0xec;
      puVar4 = local_24;
      FUN_004df599(local_34,param_1 + 0x1c);
      uVar3 = FUN_004df599(puVar4,iVar5);
      (**(code **)(iVar1 + 0x9c))(*(undefined4 *)(param_1 + 0xdc),&local_14,uVar3,uVar6);
      (**(code **)(**(int **)(param_1 + 0x5c) + 0x24))(0x10);
    }
  }
  return 1;
}

