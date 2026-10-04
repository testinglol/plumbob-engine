
float10 FUN_00641b6c(undefined4 param_1,double param_2,undefined4 param_3)

{
  undefined4 *puVar1;
  float10 fVar2;
  
  if (DAT_006ddf20 == 0) {
    fVar2 = (float10)FUN_00642122(1,param_1,param_2,0,param_2,param_3);
    return fVar2;
  }
  puVar1 = (undefined4 *)FUN_0063d796();
  *puVar1 = 0x21;
  FUN_00642397();
  return (float10)param_2;
}

