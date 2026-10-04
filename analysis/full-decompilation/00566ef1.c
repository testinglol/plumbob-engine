
uint __fastcall FUN_00566ef1(int param_1)

{
  int iVar1;
  int iVar2;
  uint in_EAX;
  undefined4 uVar3;
  int iVar4;
  undefined4 uVar5;
  int local_24;
  int local_20;
  int local_1c;
  int local_18;
  int local_14;
  int *local_10;
  int *local_c;
  int local_8;
  
  if (*(int **)(param_1 + 0x5c) != (int *)0x0) {
    in_EAX = (**(code **)(**(int **)(param_1 + 0x5c) + 0x20))(0x10);
    if ((char)in_EAX != '\0') {
      if (*(char *)(param_1 + 0x360) != '\0') {
        FUN_00567f32();
      }
      if (*(char *)(param_1 + 0x3b4) == '\0') {
        FUN_005670fe();
        if (*(int **)(param_1 + 0x3cc) != (int *)0x0) {
          local_14 = (**(code **)(**(int **)(param_1 + 0x3cc) + 0x1c))();
          iVar1 = **(int **)(param_1 + 0x3cc);
          uVar3 = FUN_005dd5e1(0x1e,0x1e,0x1e);
          (**(code **)(iVar1 + 0x20))(uVar3);
          iVar1 = **(int **)(param_1 + 0x3cc);
          uVar3 = FUN_005d49d6();
          uVar3 = FUN_004096c2(uVar3);
          (**(code **)(iVar1 + 0x50))(&local_24,uVar3);
          iVar1 = *(int *)(param_1 + 0x3d4);
          iVar4 = local_18 - local_20;
          local_8 = (*(int *)(param_1 + 0x3d0) - (local_1c - local_24) / 2) + 0x192;
          local_c = *(int **)(param_1 + 0x5c);
          local_10 = *(int **)(param_1 + 0x3cc);
          iVar2 = *local_10;
          uVar3 = FUN_005d49d6(0,0,0);
          uVar3 = FUN_004096c2(uVar3);
          (**(code **)(iVar2 + 0x78))(local_c,local_8,(iVar1 - iVar4 / 2) + 0xc,uVar3);
          (**(code **)(**(int **)(param_1 + 0x3cc) + 0x20))(local_14);
          iVar1 = *(int *)(param_1 + 0x3d4);
          local_14 = (*(int *)(param_1 + 0x3d0) - (local_1c - local_24) / 2) + 400;
          local_10 = *(int **)(param_1 + 0x5c);
          local_c = *(int **)(param_1 + 0x3cc);
          iVar2 = *local_c;
          uVar3 = FUN_005d49d6(0,0,0);
          uVar3 = FUN_004096c2(uVar3);
          (**(code **)(iVar2 + 0x78))
                    (local_10,local_14,(iVar1 - (local_18 - local_20) / 2) + 10,uVar3);
        }
        iVar1 = *(int *)(param_1 + 0x3c8);
        uVar5 = 0;
        iVar2 = **(int **)(param_1 + 0x5c);
        uVar3 = FUN_004df599(&local_24,param_1 + 0x3d0);
        (**(code **)(iVar2 + 0x9c))(*(undefined4 *)(param_1 + 0x3c8),iVar1 + 0x14,uVar3,uVar5);
      }
      if ((800 < *(int *)(param_1 + 0x84) - *(int *)(param_1 + 0x7c)) &&
         (iVar1 = *(int *)(param_1 + 0x3bc), iVar1 != 0)) {
        (**(code **)(**(int **)(param_1 + 0x5c) + 0x9c))(iVar1,iVar1 + 0x14,iVar1 + 0x14,0);
      }
      in_EAX = (**(code **)(**(int **)(param_1 + 0x5c) + 0x24))(0x10);
    }
  }
  return in_EAX & 0xffffff00;
}

