
void FUN_004d3709(void)

{
  undefined2 uVar1;
  undefined2 uVar2;
  int *piVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  
  piVar3 = (int *)(**(code **)(*DAT_006fe8bc + 0x1c))();
  uVar5 = 0xff;
  uVar1 = (**(code **)(*piVar3 + 0x38))(0xff,0,0xff);
  piVar3 = (int *)(**(code **)(*DAT_006fe8bc + 0x1c))();
  uVar4 = 0;
  uVar2 = (**(code **)(*piVar3 + 0x38))(0,0,0);
  FUN_004d33cb(uVar4,uVar5,uVar1,uVar2);
  return;
}

