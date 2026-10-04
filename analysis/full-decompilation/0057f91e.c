
undefined4 __thiscall FUN_0057f91e(int *param_1,int param_2)

{
  int *piVar1;
  int iVar2;
  undefined4 uVar3;
  
  if (param_1[0x2f] != 0) {
    if ((int *)param_1[0x74] != (int *)0x0) {
      (**(code **)(*(int *)param_1[0x74] + 0x98))(0);
    }
    (**(code **)(*(int *)param_1[0x2f] + 0x7c))();
    param_1[0x2f] = 0;
  }
  if ((int *)param_1[0x74] != (int *)0x0) {
    (**(code **)(*(int *)param_1[0x74] + 0xc))();
    if ((undefined4 *)param_1[0x74] != (undefined4 *)0x0) {
      (*(code *)**(undefined4 **)param_1[0x74])(1);
    }
    param_1[0x74] = 0;
  }
  param_1[0x3a] = param_2;
  if (param_2 != 0) {
    piVar1 = (int *)FUN_00573466(param_2);
    param_1[0x2f] = (int)piVar1;
    if (piVar1 == (int *)0x0) {
      return 0;
    }
    iVar2 = (**(code **)(*piVar1 + 4))();
    if (iVar2 == -0x5c326949) {
      (**(code **)(*(int *)param_1[0x2f] + 0x78))();
      iVar2 = (**(code **)(*(int *)param_1[0x2f] + 0xa0))();
      param_1[0x74] = iVar2;
      FUN_0057fa52();
      FUN_0057fa16();
      uVar3 = (**(code **)(*(int *)param_1[0x2f] + 0x88))(0x1a);
      (**(code **)(*param_1 + 0x84))(0x1a,uVar3,0);
    }
    else {
      (**(code **)(DAT_006f6a78 + 200))(param_1,s_Bad_Patch_ID_006d01ec);
    }
  }
  return 1;
}

