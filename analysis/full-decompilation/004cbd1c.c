
void __thiscall FUN_004cbd1c(int param_1,int *param_2,int *param_3)

{
  char cVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  int local_28;
  int local_24;
  int local_20;
  int local_1c;
  int local_18;
  int local_14;
  int local_10;
  int local_c;
  int local_8;
  
  iVar4 = *(int *)(param_1 + 0x24);
  if (iVar4 == 1) {
    FUN_004e5425(*(undefined4 *)(param_1 + 0x28),param_2,param_3,0);
  }
  else if (iVar4 == 2) {
    FUN_004e550a(*(undefined4 *)(param_1 + 0x44),param_2,param_3);
  }
  else if (2 < iVar4) {
    if (iVar4 < 5) {
      FUN_004e5493(*(undefined4 *)(param_1 + 0x40),*(undefined4 *)(param_1 + 0x3c),param_2,param_3);
    }
    else if (iVar4 == 5) {
      local_8 = param_1 + 0x48;
      cVar1 = FUN_005a5e72();
      if ((cVar1 != '\0') && (cVar1 = (**(code **)(*param_2 + 0x20))(0x10), cVar1 != '\0')) {
        if (*(char *)(param_1 + 0x4c) == '\0') {
          iVar4 = FUN_004096c2();
          local_28 = *(int *)(iVar4 + 0x14);
          local_24 = *(int *)(iVar4 + 0x18);
          local_20 = *(int *)(iVar4 + 0x1c);
          local_1c = *(int *)(iVar4 + 0x20);
          local_18 = local_28;
          local_10 = local_20;
          if (local_20 - local_28 < param_3[2] - *param_3) {
            local_18 = (((param_3[2] - *param_3) - local_20) + local_28) / 2 + *param_3;
            local_10 = local_20 + local_18;
            local_18 = local_18 + local_28;
          }
          iVar4 = param_3[3] - param_3[1];
          local_14 = local_24;
          local_c = local_1c;
          if (local_1c - local_24 < iVar4) {
            local_c = ((iVar4 - local_1c) + local_24) / 2 + param_3[1];
            local_14 = local_24 + local_c;
            local_c = local_1c + local_c;
          }
          iVar4 = *param_2;
          uVar3 = FUN_004096c2(&local_28,&local_18,0);
          (**(code **)(iVar4 + 0x9c))(uVar3);
        }
        else {
          local_c = param_3[3] - *(int *)(param_1 + 0x5c);
          local_18 = *param_3 + *(int *)(param_1 + 0x50);
          local_10 = param_3[2] - *(int *)(param_1 + 0x58);
          local_14 = param_3[1] + *(int *)(param_1 + 0x54);
          iVar4 = *param_2;
          iVar2 = FUN_004096c2(&local_18,0,0);
          uVar3 = FUN_004096c2(iVar2 + 0x14);
          (**(code **)(iVar4 + 0xbc))(uVar3);
        }
        (**(code **)(*param_2 + 0x24))(0x10);
      }
    }
  }
  return;
}

