
void __thiscall FUN_004b0597(int param_1,int param_2,int param_3,undefined4 param_4)

{
  undefined4 uVar1;
  char cVar2;
  int iVar3;
  int *piVar4;
  undefined1 local_30 [16];
  undefined1 local_20 [16];
  int *local_10;
  int local_c;
  int local_8;
  
  cVar2 = FUN_004b465e();
  if (cVar2 != '\0') {
    piVar4 = *(int **)(param_1 + 0x70);
    cVar2 = (**(code **)(*piVar4 + 0x20))(0x10);
    if (cVar2 != '\0') {
      if (0 < param_3) {
        local_8 = param_3;
        iVar3 = param_2;
        do {
          FUN_005de822(iVar3);
          FUN_005de822(iVar3);
          (**(code **)(*piVar4 + 0x9c))(*(undefined4 *)(param_1 + 0x74),local_30,local_20,0);
          iVar3 = iVar3 + 0x10;
          local_8 = local_8 + -1;
        } while (local_8 != 0);
      }
      (**(code **)(*piVar4 + 0x24))(0x10);
    }
  }
  cVar2 = FUN_004b4665();
  if (cVar2 != '\0') {
    piVar4 = *(int **)(*(int *)(param_1 + 0x70) + 0x5c);
    local_10 = piVar4;
    cVar2 = (**(code **)(*piVar4 + 0x20))(0x10);
    if (cVar2 != '\0') {
      if (0 < param_3) {
        uVar1 = *(undefined4 *)(*(int *)(param_1 + 0x74) + 0x5c);
        local_8 = param_2;
        local_c = param_3;
        do {
          FUN_005de822(local_8);
          FUN_005de822(local_8);
          (**(code **)(*piVar4 + 0x9c))(uVar1,local_20,local_30,0);
          local_8 = local_8 + 0x10;
          local_c = local_c + -1;
        } while (local_c != 0);
        local_c = 0;
        piVar4 = local_10;
      }
      (**(code **)(*piVar4 + 0x24))(0x10);
    }
  }
  if (*(char *)(param_1 + 0x17e) != '\0') {
    FUN_004b038a(*(undefined4 *)(param_1 + 0x70),param_4);
    if (*(char *)(param_1 + 0x78) != '\0') {
      *(undefined4 *)(param_1 + 0x7c) = 0;
    }
    if (0 < param_3) {
      do {
        FUN_004b06db(param_2,0xff0000,param_4,param_1 + 0x28);
        param_2 = param_2 + 0x10;
        param_3 = param_3 + -1;
      } while (param_3 != 0);
    }
    FUN_004b048c(param_4);
  }
  return;
}

