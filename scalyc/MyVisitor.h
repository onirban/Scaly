#ifndef __scalyc__MyVisitor__
#define __scalyc__MyVisitor__
#include "scalyc.h"
using namespace scaly;
namespace scalyc {

class MyVisitor : public SyntaxVisitor {
public:
    virtual bool openProgram(Program* program);
    virtual void closeProgram(Program* program);
    _VarString* programName;
    _VarString* programDirectory;
    virtual bool openCompilationUnit(CompilationUnit* compilationUnit);
    virtual void closeCompilationUnit(CompilationUnit* compilationUnit);
    virtual bool openStatementWithSemicolon(StatementWithSemicolon* statementWithSemicolon);
    virtual void closeStatementWithSemicolon(StatementWithSemicolon* statementWithSemicolon);
    virtual bool openUseDeclaration(UseDeclaration* useDeclaration);
    virtual void closeUseDeclaration(UseDeclaration* useDeclaration);
    virtual bool openConstantDeclaration(ConstantDeclaration* constantDeclaration);
    virtual void closeConstantDeclaration(ConstantDeclaration* constantDeclaration);
    virtual bool openVariableDeclaration(VariableDeclaration* variableDeclaration);
    virtual void closeVariableDeclaration(VariableDeclaration* variableDeclaration);
    virtual bool openFunctionDeclaration(FunctionDeclaration* functionDeclaration);
    virtual void closeFunctionDeclaration(FunctionDeclaration* functionDeclaration);
    virtual bool openEnumDeclaration(EnumDeclaration* enumDeclaration);
    virtual void closeEnumDeclaration(EnumDeclaration* enumDeclaration);
    _VarString* enumDeclarationName;
    virtual bool openClassDeclaration(ClassDeclaration* classDeclaration);
    virtual void closeClassDeclaration(ClassDeclaration* classDeclaration);
    _VarString* classDeclarationName;
    virtual bool openInitializerDeclaration(InitializerDeclaration* initializerDeclaration);
    virtual void closeInitializerDeclaration(InitializerDeclaration* initializerDeclaration);
    virtual bool openCodeBlock(CodeBlock* codeBlock);
    virtual void closeCodeBlock(CodeBlock* codeBlock);
    virtual bool openSimpleExpression(SimpleExpression* simpleExpression);
    virtual void closeSimpleExpression(SimpleExpression* simpleExpression);
    virtual bool openPathIdentifier(PathIdentifier* pathIdentifier);
    virtual void closePathIdentifier(PathIdentifier* pathIdentifier);
    virtual void visitPathItem(PathItem* pathItem);
    virtual bool openInitializer(Initializer* initializer);
    virtual void closeInitializer(Initializer* initializer);
    virtual bool openBindingInitializer(BindingInitializer* bindingInitializer);
    virtual void closeBindingInitializer(BindingInitializer* bindingInitializer);
    virtual bool openPatternInitializer(PatternInitializer* patternInitializer);
    virtual void closePatternInitializer(PatternInitializer* patternInitializer);
    virtual bool openAdditionalInitializer(AdditionalInitializer* additionalInitializer);
    virtual void closeAdditionalInitializer(AdditionalInitializer* additionalInitializer);
    virtual void visitOverrideWord(OverrideWord* overrideWord);
    virtual void visitStaticWord(StaticWord* staticWord);
    virtual void visitIdentifierFunction(IdentifierFunction* identifierFunction);
    virtual bool openFunctionSignature(FunctionSignature* functionSignature);
    virtual void closeFunctionSignature(FunctionSignature* functionSignature);
    virtual bool openFunctionResult(FunctionResult* functionResult);
    virtual void closeFunctionResult(FunctionResult* functionResult);
    virtual bool openParameterClause(ParameterClause* parameterClause);
    virtual void closeParameterClause(ParameterClause* parameterClause);
    virtual bool openConstParameter(ConstParameter* constParameter);
    virtual void closeConstParameter(ConstParameter* constParameter);
    _VarString* constParameterName;
    virtual bool openVarParameter(VarParameter* varParameter);
    virtual void closeVarParameter(VarParameter* varParameter);
    _VarString* varParameterName;
    virtual bool openThrowsClause(ThrowsClause* throwsClause);
    virtual void closeThrowsClause(ThrowsClause* throwsClause);
    virtual bool openEnumMember(EnumMember* enumMember);
    virtual void closeEnumMember(EnumMember* enumMember);
    virtual void visitEnumCase(EnumCase* enumCase);
    virtual bool openAdditionalCase(AdditionalCase* additionalCase);
    virtual void closeAdditionalCase(AdditionalCase* additionalCase);
    virtual bool openClassBody(ClassBody* classBody);
    virtual void closeClassBody(ClassBody* classBody);
    virtual bool openGenericArgumentClause(GenericArgumentClause* genericArgumentClause);
    virtual void closeGenericArgumentClause(GenericArgumentClause* genericArgumentClause);
    virtual void visitGenericParameter(GenericParameter* genericParameter);
    virtual bool openClassMember(ClassMember* classMember);
    virtual void closeClassMember(ClassMember* classMember);
    virtual bool openPrefixExpression(PrefixExpression* prefixExpression);
    virtual void closePrefixExpression(PrefixExpression* prefixExpression);
    virtual bool openPostfixExpression(PostfixExpression* postfixExpression);
    virtual void closePostfixExpression(PostfixExpression* postfixExpression);
    virtual bool openBinaryOperation(BinaryOperation* binaryOperation);
    virtual void closeBinaryOperation(BinaryOperation* binaryOperation);
    virtual bool openAssignment(Assignment* assignment);
    virtual void closeAssignment(Assignment* assignment);
    virtual bool openTypeQuery(TypeQuery* typeQuery);
    virtual void closeTypeQuery(TypeQuery* typeQuery);
    virtual bool openTypeCast(TypeCast* typeCast);
    virtual void closeTypeCast(TypeCast* typeCast);
    virtual bool openCatchClause(CatchClause* catchClause);
    virtual void closeCatchClause(CatchClause* catchClause);
    virtual bool openWildCardCatchPattern(WildCardCatchPattern* wildCardCatchPattern);
    virtual void closeWildCardCatchPattern(WildCardCatchPattern* wildCardCatchPattern);
    virtual bool openPathItemCatchPattern(PathItemCatchPattern* pathItemCatchPattern);
    virtual void closePathItemCatchPattern(PathItemCatchPattern* pathItemCatchPattern);
    virtual void visitOperatorPostfix(OperatorPostfix* operatorPostfix);
    virtual bool openFunctionCall(FunctionCall* functionCall);
    virtual void closeFunctionCall(FunctionCall* functionCall);
    virtual bool openExplicitMemberExpression(ExplicitMemberExpression* explicitMemberExpression);
    virtual void closeExplicitMemberExpression(ExplicitMemberExpression* explicitMemberExpression);
    virtual bool openSubscript(Subscript* subscript);
    virtual void closeSubscript(Subscript* subscript);
    virtual bool openExpressionElement(ExpressionElement* expressionElement);
    virtual void closeExpressionElement(ExpressionElement* expressionElement);
    virtual bool openNamedMemberPostfix(NamedMemberPostfix* namedMemberPostfix);
    virtual void closeNamedMemberPostfix(NamedMemberPostfix* namedMemberPostfix);
    virtual void visitIdentifierExpression(IdentifierExpression* identifierExpression);
    virtual void visitLiteralExpression(LiteralExpression* literalExpression);
    virtual bool openIfExpression(IfExpression* ifExpression);
    virtual void closeIfExpression(IfExpression* ifExpression);
    virtual bool openSwitchExpression(SwitchExpression* switchExpression);
    virtual void closeSwitchExpression(SwitchExpression* switchExpression);
    virtual bool openForExpression(ForExpression* forExpression);
    virtual void closeForExpression(ForExpression* forExpression);
    virtual bool openParenthesizedExpression(ParenthesizedExpression* parenthesizedExpression);
    virtual void closeParenthesizedExpression(ParenthesizedExpression* parenthesizedExpression);
    virtual bool openReturnExpression(ReturnExpression* returnExpression);
    virtual void closeReturnExpression(ReturnExpression* returnExpression);
    virtual bool openThrowExpression(ThrowExpression* throwExpression);
    virtual void closeThrowExpression(ThrowExpression* throwExpression);
    virtual bool openBreakExpression(BreakExpression* breakExpression);
    virtual void closeBreakExpression(BreakExpression* breakExpression);
    virtual bool openInitializerCall(InitializerCall* initializerCall);
    virtual void closeInitializerCall(InitializerCall* initializerCall);
    virtual bool openThisDot(ThisDot* thisDot);
    virtual void closeThisDot(ThisDot* thisDot);
    virtual bool openThisSubscript(ThisSubscript* thisSubscript);
    virtual void closeThisSubscript(ThisSubscript* thisSubscript);
    virtual void visitThisWord(ThisWord* thisWord);
    virtual bool openSuperDot(SuperDot* superDot);
    virtual void closeSuperDot(SuperDot* superDot);
    virtual bool openSuperSubscript(SuperSubscript* superSubscript);
    virtual void closeSuperSubscript(SuperSubscript* superSubscript);
    virtual bool openElseClause(ElseClause* elseClause);
    virtual void closeElseClause(ElseClause* elseClause);
    virtual bool openCurliedSwitchBody(CurliedSwitchBody* curliedSwitchBody);
    virtual void closeCurliedSwitchBody(CurliedSwitchBody* curliedSwitchBody);
    virtual bool openNakedSwitchBody(NakedSwitchBody* nakedSwitchBody);
    virtual void closeNakedSwitchBody(NakedSwitchBody* nakedSwitchBody);
    virtual bool openSwitchCase(SwitchCase* switchCase);
    virtual void closeSwitchCase(SwitchCase* switchCase);
    virtual bool openItemCaseLabel(ItemCaseLabel* itemCaseLabel);
    virtual void closeItemCaseLabel(ItemCaseLabel* itemCaseLabel);
    virtual void visitDefaultCaseLabel(DefaultCaseLabel* defaultCaseLabel);
    virtual bool openCaseItem(CaseItem* caseItem);
    virtual void closeCaseItem(CaseItem* caseItem);
    virtual bool openForEach(ForEach* forEach);
    virtual void closeForEach(ForEach* forEach);
    virtual bool openPlainFor(PlainFor* plainFor);
    virtual void closePlainFor(PlainFor* plainFor);
    virtual void visitWildcardPattern(WildcardPattern* wildcardPattern);
    virtual bool openIdentifierPattern(IdentifierPattern* identifierPattern);
    virtual void closeIdentifierPattern(IdentifierPattern* identifierPattern);
    _VarString* identifierPatternIdentifier;
    virtual bool openTuplePattern(TuplePattern* tuplePattern);
    virtual void closeTuplePattern(TuplePattern* tuplePattern);
    virtual bool openExpressionPattern(ExpressionPattern* expressionPattern);
    virtual void closeExpressionPattern(ExpressionPattern* expressionPattern);
    virtual bool openTuplePatternElement(TuplePatternElement* tuplePatternElement);
    virtual void closeTuplePatternElement(TuplePatternElement* tuplePatternElement);
    virtual bool openBlockCaseContent(BlockCaseContent* blockCaseContent);
    virtual void closeBlockCaseContent(BlockCaseContent* blockCaseContent);
    virtual void visitEmptyCaseContent(EmptyCaseContent* emptyCaseContent);
    virtual void visitThisInit(ThisInit* thisInit);
    virtual void visitThisMember(ThisMember* thisMember);
    virtual void visitSuperInit(SuperInit* superInit);
    virtual void visitSuperMember(SuperMember* superMember);
    virtual bool openTypeIdentifier(TypeIdentifier* typeIdentifier);
    virtual void closeTypeIdentifier(TypeIdentifier* typeIdentifier);
    _VarString* typeIdentifierName;
    virtual bool openArrayType(ArrayType* arrayType);
    virtual void closeArrayType(ArrayType* arrayType);
    virtual bool openTypeAnnotation(TypeAnnotation* typeAnnotation);
    virtual void closeTypeAnnotation(TypeAnnotation* typeAnnotation);
    virtual bool openSubtypeIdentifier(SubtypeIdentifier* subtypeIdentifier);
    virtual void closeSubtypeIdentifier(SubtypeIdentifier* subtypeIdentifier);
    virtual void visitOptionalType(OptionalType* optionalType);
    virtual bool openTypeInheritanceClause(TypeInheritanceClause* typeInheritanceClause);
    virtual void closeTypeInheritanceClause(TypeInheritanceClause* typeInheritanceClause);
    virtual bool openInheritance(Inheritance* inheritance);
    virtual void closeInheritance(Inheritance* inheritance);

    virtual bool _isMyVisitor();
};

}
#endif // __scalyc__MyVisitor__
