
undefined4 __fastcall FUN_00522a12(int param_1)

{
  int iVar1;
  char cVar2;
  int iVar3;
  undefined4 uVar4;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  int local_14;
  int local_10;
  int local_c;
  int local_8;
  
  if (*(int **)(param_1 + 0x5c) != (int *)0x0) {
    cVar2 = (**(code **)(**(int **)(param_1 + 0x5c) + 0x20))(0x10);
    if (cVar2 != '\0') {
      iVar1 = *(int *)(param_1 + 0x128);
      if (iVar1 != 0) {
        local_14 = *(int *)(iVar1 + 0x14);
        local_10 = *(int *)(iVar1 + 0x18);
        local_c = *(int *)(iVar1 + 0x1c) / 3;
        local_8 = *(int *)(iVar1 + 0x20) / 3;
        (**(code **)(**(int **)(param_1 + 0x5c) + 0xc0))(iVar1,&local_14,param_1 + 0x1c,1);
      }
      iVar1 = *(int *)(param_1 + 300);
      if (iVar1 != 0) {
        local_14 = *(int *)(iVar1 + 0x14) + 0x11 + *(int *)(param_1 + 0x7c);
        local_c = *(int *)(iVar1 + 0x1c) + 0x11 + *(int *)(param_1 + 0x7c);
        local_10 = *(int *)(iVar1 + 0x18) + 8 + *(int *)(param_1 + 0x80);
        local_8 = *(int *)(iVar1 + 0x20) + 8 + *(int *)(param_1 + 0x80);
        (**(code **)(**(int **)(param_1 + 0x5c) + 0x9c))
                  (*(undefined4 *)(param_1 + 300),iVar1 + 0x14,&local_14,0);
      }
      iVar1 = *(int *)(param_1 + 0x130);
      if (iVar1 != 0) {
        iVar3 = (((*(int *)(*(int *)(param_1 + 0x11c) + 0x80) -
                  *(int *)(*(int *)(param_1 + 0x11c) + 0x88)) * 3) / 2 - *(int *)(param_1 + 0x80)) +
                5 + *(int *)(param_1 + 0x88);
        local_10 = *(int *)(iVar1 + 0x18) + iVar3 + *(int *)(param_1 + 0x80);
        local_8 = *(int *)(iVar1 + 0x20) + iVar3 + *(int *)(param_1 + 0x80);
        iVar3 = ((*(int *)(param_1 + 0x84) - *(int *)(param_1 + 0x7c)) + -0x17) / 2;
        local_14 = *(int *)(iVar1 + 0x14) + iVar3 + *(int *)(param_1 + 0x7c);
        local_c = *(int *)(iVar1 + 0x1c) + iVar3 + *(int *)(param_1 + 0x7c);
        (**(code **)(**(int **)(param_1 + 0x5c) + 0x9c))(iVar1,iVar1 + 0x14,&local_14,0);
      }
      cVar2 = FUN_005a5e72();
      if (cVar2 != '\0') {
        local_14 = *(int *)(param_1 + 0x7c) + 10;
        local_1c = 0x2d;
        local_18 = 0x2d;
        local_c = *(int *)(param_1 + 0x7c) + 0x37;
        local_24 = 0;
        local_10 = *(int *)(param_1 + 0x80) + 10;
        local_20 = 0;
        local_8 = *(int *)(param_1 + 0x80) + 0x37;
        iVar1 = **(int **)(param_1 + 0x5c);
        uVar4 = FUN_004096c2(&local_24,&local_14,0);
        (**(code **)(iVar1 + 0x9c))(uVar4);
      }
      (**(code **)(**(int **)(param_1 + 0x5c) + 0x24))(0x10);
    }
  }
  return 1;
}

