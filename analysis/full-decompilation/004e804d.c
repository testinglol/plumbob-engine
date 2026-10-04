
uint FUN_004e804d(int *param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 uVar2;
  int *piVar3;
  char cVar4;
  byte bVar5;
  undefined1 uVar6;
  uint uVar7;
  undefined2 local_6;
  
  iVar1 = *(int *)(DAT_006e486c + 0x3c);
  if (iVar1 == 0) {
    uVar7 = DAT_006e486c & 0xffffff00;
  }
  else {
    uVar2 = *(undefined4 *)(iVar1 + 0x5c);
    local_6 = 0;
    cVar4 = (**(code **)(*param_1 + 0x20))(0x10);
    if (cVar4 != '\0') {
      bVar5 = (**(code **)(*param_1 + 0x9c))(iVar1,param_2,param_1 + 5,0);
      local_6 = (undefined2)(((uint)bVar5 << 0x18) >> 0x10);
      (**(code **)(*param_1 + 0x24))(0x10);
    }
    piVar3 = (int *)param_1[0x17];
    cVar4 = (**(code **)(*piVar3 + 0x20))(0x10);
    if (cVar4 != '\0') {
      uVar6 = (**(code **)(*piVar3 + 0x9c))(uVar2,param_2,param_1 + 5,0);
      local_6 = CONCAT11(local_6._1_1_,uVar6);
      (**(code **)(*(int *)param_1[0x17] + 0x24))(0x10);
    }
    if ((local_6._1_1_ == '\0') && ((char)local_6 == '\0')) {
      uVar7 = 0;
    }
    else {
      uVar7 = 1;
    }
  }
  return uVar7;
}

