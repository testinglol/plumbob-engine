
float10 FUN_00641bc0(undefined4 param_1,undefined4 param_2,undefined8 param_3,double param_4,
                    undefined4 param_5)

{
  int iVar1;
  float10 fVar2;
  
  iVar1 = FUN_00641f0b(param_1,&param_4,param_5);
  if (iVar1 == 0) {
    FUN_00641c58();
  }
  iVar1 = FUN_006421f7(param_1);
  if ((DAT_006ddf20 == 0) && (iVar1 != 0)) {
    fVar2 = (float10)FUN_00642122(iVar1,param_2,param_3,0,param_4,param_5);
    return fVar2;
  }
  FUN_006421aa(iVar1);
  FUN_00642397();
  return (float10)param_4;
}

